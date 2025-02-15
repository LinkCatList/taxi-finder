#include "map.h"

Map::Map(const std::string& SpritePath) 
    : Texture(SpritePath)
    , Sprite(Texture)
{}

sf::Sprite Map::GetSprite() {
    return Sprite;
}

void Map::Build(const std::string& jsonPath) {
    std::ifstream file(jsonPath);
    auto data = nlohmann::json::parse(file);

    std::vector<Point> points;
    for (size_t i = 0; i < data["graph"].size(); ++i) {
        points.emplace_back(data["graph"][i]["x"], data["graph"][i]["y"]);
    }

    IdToPoint = points;

    for (size_t i = 0; i < points.size(); ++i) {
        PointToId[points[i]] = i;
    }

    Roads.resize(points.size());
    for (size_t i = 0; i < points.size(); ++i) {
        for (size_t j = 0; j < points.size(); ++j) {
            if (i == j) {
                continue;
            }

            if (std::abs(points[i].x - points[j].x) <= EPS || std::abs(points[i].y - points[j].y) <= EPS) {
                Roads[i].emplace_back(j, points[i].SquareDist(points[j]));
                Roads[j].emplace_back(i, points[i].SquareDist(points[j]));
            }
        }
    }
}

std::vector<Point> Map::GetPath(Point Start, Point Finish) {
    int start = PointToId[Start];
    int finish = PointToId[Finish];
    std::vector<int> dist(Roads.size(), INF);
    std::vector<int> parent(Roads.size(), -1);
    std::queue<int> queue;

    queue.push(start);
    dist[start] = 0;
    while (!queue.empty()) {
        int vertex = queue.front();
        queue.pop();
        for (const auto& [to, weight] : Roads[vertex]) {
            if (dist[to] > dist[vertex] + weight) {
                dist[to] = dist[vertex] + weight;
                parent[to] = vertex;
                queue.push(to);
            }
        }
    }

    std::vector<Point> path;
    while (parent[finish] != -1) {
        path.push_back(IdToPoint[finish]);
        finish = parent[finish];
    }

    // std::reverse(path.begin(), path.end());
    return path;
}

std::vector<Point> Map::GetPoints() {
    return IdToPoint;
}
