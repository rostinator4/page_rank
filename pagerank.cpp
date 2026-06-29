#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
const double UNI_PROB = 1;

template <typename K, typename V>
void printHashMap(std::unordered_map<K, V>* web_map){
    for(const auto& [key, value] : *web_map){
        std::cout << key << " : " << value << std::endl;
    }
}

std::unordered_map<std::string, double> PageRank(std::unordered_map<std::string,
                                                                    std::vector<std::string>>*
                                                     web_map)
{
    double pageProb = UNI_PROB / web_map->size();
    std::unordered_map<std::string, double> pageRanks;

    for(const auto& [curr_page, _] : *web_map){
        double curr_page_prob = 0;

        for(const auto& [link_page, out_links] : *web_map){
            if (curr_page != link_page){
                size_t curr_size = out_links.size(); //size of outgoing links

                for(size_t index = 0; index < curr_size; index++){
                    if (out_links[index] == curr_page)
                    {
                        curr_page_prob += (pageProb / curr_size);
                    }
                    
                }
            }
        }
        pageRanks[curr_page] = curr_page_prob;
    }
    return pageRanks;
    
}

int main(int argc, char *argv[])
{
    std::unordered_map<std::string, std::vector<std::string>> web_map;
    std::unordered_map<std::string, double> pageRanks;
    std::string newFile = "testing/test1.txt";
    std::string newLine;
    std::ifstream myFile(newFile);

    if (!myFile.is_open())
    {
        std::cerr << "The file could not be open" << std::endl;
        return 1;
    }

    while (std::getline(myFile, newLine))
    {
        std::istringstream stream(newLine);
        std::string firstWord;
        std::string newWord;

        stream >> firstWord;
        auto &wordList = web_map[firstWord];

        while (stream >> newWord)
        {

            wordList.push_back(newWord);
        }
    }

    myFile.close();

    pageRanks = PageRank(&web_map);
    printHashMap(&pageRanks);

    return 0;
}