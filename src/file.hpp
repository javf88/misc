/******************************************************************************/
/*    INCLUDED FILES                                                          */
/******************************************************************************/

#include <cstddef>
#include <iostream>
#include <fstream>

/******************************************************************************/
/*    API                                                                     */
/******************************************************************************/

struct File
{
    std::string name;
    std::fstream file;

    int n;
    int q;
    std::string listing; //file has been already used
    std::string queries;

    File(std::string name): name(name)
    {
        this->file.open(name, std::ios::in);
        if (this->file.is_open())
        {
            std::cout << this->name << " is opened" << std::endl;
            this->setup();
        }
        else
        {
            std::cout << this->name << " is not opened" << std::endl;
        }
    }

    ~File()
    {
        if (this->file.is_open())
        {
            std::cout << "Closing file " << this->name << std::endl;
            this->file.close();
        }
        else
        {
            std::cout << this->name << " was not opened" << std::endl;
        }
    }

    void setup()
    {
        using namespace std;

        string line;
        size_t start  = 0;
        size_t pos;

        // reading the whole input
        getline(this->file, line, '\0');

        // extracting n and q
        pos = line.find(' ');
        this->n = std::stoi(line.substr(start, pos));
        start = pos;
        pos = line.find('\n', pos + 1);
        this->q = std::stoi(line.substr(start + 1, pos));

        // extracting listing(file)
        start = pos;
        for (int i = 0; i < n; ++i)
            pos = line.find('\n', pos + 1);
        this->listing = line.substr(start + 1, pos - start - 1);

        // extracting queries
        start = pos;
        for (int i = 0; i < q; ++i)
            pos = line.find('\n', pos + 1);
        this->queries = line.substr(start + 1, pos - start - 1);
        // formatting queries for a better ingestion
        std::replace(queries.begin(), queries.end(), '.', ' ');
        std::replace(queries.begin(), queries.end(), '~', ' ');
    }

    void find(std::string query, std::string file)
    {
        size_t pos = query.find(' ');
        std::string tag = query.substr(0, pos);
        size_t start = file.find("<" + tag);

        if (start == 0)
        {
            std::string nestedQuery = query.substr(pos + 1);
            if (nestedQuery.find(' ') == std::string::npos)
            {
                // find var
                std::string content;
                size_t end = file.find('>');

                content = file.substr(1, end);
                read(nestedQuery, content);
            }
            else
            {
                // extract nested tag
                std::string nestedFile;
                size_t end;

                pos = file.find(">");
                end = file.find("</" + tag);
                if (end - pos == 1)
                {
                    pos = file.find("<", end + 1);
                    nestedFile = file.substr(pos);
                }
                else
                {
                    start = file.find("<", 1);
                    nestedFile = file.substr(start, end - start - 1);
                }

                find(nestedQuery, nestedFile);
            }
        }
        else
        {
            if (start == std::string::npos)
            {
                std::cout << "Not Found!" << std::endl;
            }
            else
            {
                // remove first tag
                std::string nextFile = removeTag(file);
                find(query, nextFile);
            }
        }
    }

    void read(std::string var, std::string content)
    {
        size_t start = content.find(" " + var + " = ");
        if (start != std::string::npos)
        {
            size_t end;
            start = content.find('"', start) + 1;
            end = content.find('"', start);

            std::cout << content.substr(start, end - start) << std::endl;
        }
        else
        {
            std::cout << "Not Found!" << std::endl;
        }
    }

    std::string removeTag(std::string& fromFile)
    {
        std::string wrongTag;
        size_t start = fromFile.find(' ');
        size_t end = fromFile.find('>');

        if (end < start)
            start = end;

        wrongTag = fromFile.substr(1, start - 1);
        end = fromFile.find(wrongTag + ">", start);
        start = fromFile.find("<", end);
        if (start == std::string::npos)
            start = fromFile.size();

        // nextFile from start to EOF
        return fromFile.substr(start);
    }

    friend std::ostream& operator<<(std::ostream& os, const File& f)
    {
        std::string line;
        size_t start = 0;
        size_t pos = 0;

        std::cout << "n: " << f.n << std::endl;
        std::cout << "q: " << f.q << std::endl;

        for (int i = 0; i < f.n; ++i)
        {
            pos = f.listing.find('\n', start) + 1;
            line = f.listing.substr(start, pos - start);
            start = pos;
            std::cout << "l: " << line;
        }

        std::cout << std::endl;

        for (int i = 0, start = pos = 0; i < f.q; ++i)
        {
            pos = f.queries.find('\n', start) + 1;
            line = f.queries.substr(start, pos - start);
            start = pos;
            std::cout << "q: " << line;
        }

        return os;
    }
};
