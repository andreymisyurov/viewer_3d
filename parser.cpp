#ifndef MESH_H
#define MESH_H

#include <fstream>
#include <vector>

struct Data {
    float m_x;
    float m_y;
    float m_z;
};

class Parser {
private:
    Parser() {}
    Parser(const Parser&) = delete;
    Parser& operator=(const Parser&) = delete;

    std::vector<Data> m_vec3;
    std::vector<std::vector<int>> m_faces;

public:
    static auto getInstanse() -> Parser& {
        static Parser instanse;
        return instanse;
    }

    auto clearData() -> void {
        m_vec3.clear();
        m_faces.clear();
    }

    auto getObj(const char* filename) -> std::pair<std::vector<Data>,
                                            std::vector<std::vector<int>>> {
        std::ifstream in(filename, std::ios::in);
        std::string line;
        std::pair<std::vector<Data>, std::vector<std::vector<int>>> result;
        Data pick;
        while (std::getline(in, line)) {
            if (line.substr(0, 2) == "v ") {
                line = line.substr(2, line.size());
                auto check = sscanf(line.c_str(), "%f %f %f", &pick.m_x, &pick.m_y, &pick.m_z);
                if(check != 3) {
                    return result;
                }
                m_vec3.push_back(pick);
            } else if (line.substr(0, 1) == "f") {
                line = line.substr(1, line.size());
                std::vector<int> indexes;
                while (line.find(" ") != std::string::npos) {
                    line = line.substr(line.find(" "), line.size());
                    indexes.push_back(atoi(line.c_str()));
                    line.erase(0, 1);
                }
                m_faces.push_back(indexes);
            }
        }
        result.first = m_vec3;
        result.second = m_faces;
        return result;
    }
};




struct MomentoData {
    float m_xMove;
    float m_yMove;
    float m_zMove;
    float m_xRotate;
    float m_yRotate;
    float m_zRotate;
    float m_scale;
    std::pair<std::vector<Data>, std::vector<std::vector<int>>> pair;
};

class Momento {
public:
    void saveData(MomentoData data) {
        m_data = data;
    }

    MomentoData getData() {
        return m_data;
    }

    auto setText(std::string title, std::string verts, std::string faces) -> void {
        m_title = title;
        m_verteres = verts;
        m_faces= faces;
    }

    auto getTitle() -> std::string{
        return m_title;
    }

    auto getVerteres() -> std::string {
        return m_verteres;
    }

    auto getFaces() -> std::string{
        return m_faces;
    }

private:
    struct MomentoData m_data;
    std::string m_title;
    std::string m_verteres;
    std::string m_faces;
};

#endif  // MESH_H
