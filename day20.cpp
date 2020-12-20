#include <algorithm>
#include <array>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>
using std::cout;
using std::endl;
using std::ifstream;
using std::istream;
using std::istringstream;
using std::sqrt;
using std::string;
using std::swap;
using std::vector;

const int TILESIZE = 10;

class ImageProcessor {
public:
   ImageProcessor(const string &filename) {
      ifstream ifile(filename);
      string line;
      while (getline(ifile, line)) {
         string s;
         int i;
         istringstream iline(line);
         iline >> s >> i;
         tileIDs.push_back(i);
         tiles.emplace_back(vector<string>());
         while (getline(ifile, line)) {
            if (line.empty())
               break;
            tiles.back().push_back(line);
         }
      }

      tilesUsed = vector<bool>(tiles.size());
      int gridSize = sqrt(tiles.size());
      grid = vector<vector<Tile>>(gridSize, vector<Tile>(gridSize));
      backtrack(0);

      const int blocksize = TILESIZE - 2;
      vector<string> image(blocksize * gridSize,
                           string(blocksize * gridSize, ' '));
      for (int y = 0; y < blocksize * gridSize; ++y)
         for (int x = 0; x < blocksize * gridSize; ++x) {
            auto tx = x / blocksize;
            auto ty = y / blocksize;
            auto bx = x % blocksize + 1; // skip left edge
            auto by = y % blocksize + 1; // skip top edge
            image[y][x] = getChar(grid[tx][ty], bx, by);
         }

      processImage(image);
   }

private:
   const vector<string> seaHorse{"                  # ",//
                                 "#    ##    ##    ###",//
                                 " #  #  #  #  #  #   "};

   struct Tile {
      int tileIndex;//into tiles vector
      int transform;//0..7
   };

   bool matchLR(const Tile &left, const Tile &right) {
      for (int i = 0; i < TILESIZE; ++i)
         if (getChar(left, TILESIZE - 1, i) != getChar(right, 0, i))
            return false;
      return true;
   }

   bool matchUD(const Tile &up, const Tile &down) {
      for (int i = 0; i < TILESIZE; ++i)
         if (getChar(up, i, TILESIZE - 1) != getChar(down, i, 0))
            return false;
      return true;
   }

   char getChar(const Tile &t, int x, int y) {
      return transformAndGet(tiles[t.tileIndex], t.transform, x, y);
   }

   static char &transformAndGet(vector<string> &v, int t, int x, int y) {
      const int n = v.size();//matrix must be square
      if (t & 1)
         x = n - 1 - x;//reflect about horizontal axis
      if (t & 2)
         y = n - 1 - y;//reflect about vertical axis
      if (t & 4)
         swap(x, y);//reflect about x=y diagonal
      return v[y][x];
   };

   bool backtrack(int loc) {
      const int size = grid.size();
      if (loc == size * size) {
         cout << "Day 20 star 1 = "
              << tileIDs[grid[0][0].tileIndex] *
                       tileIDs[grid[0][size - 1].tileIndex] *
                       tileIDs[grid[size - 1][0].tileIndex] *
                       tileIDs[grid[size - 1][size - 1].tileIndex]
              << "\n";
         return true;
      }
      int x = loc % size;
      int y = loc / size;
      for (int t = 0; t < tilesUsed.size(); ++t) {
         if (tilesUsed[t])
            continue;
         Tile tile{t, 0};
         tilesUsed[t] = true;
         for (tile.transform = 0; tile.transform < 8; ++tile.transform) {
            if (x > 0 && !matchLR(grid[x - 1][y], tile))
               continue;
            if (y > 0 && !matchUD(grid[x][y - 1], tile))
               continue;

            grid[x][y] = tile;
            if (backtrack(loc + 1))
               return true;
         }
         tilesUsed[t] = false;
      }
      return false;
   }

   bool matchAndMaskSeaMonster(vector<string> &image, int t, int x, int y) {
      for (int dy = 0; dy < seaHorse.size(); ++dy)
         for (int dx = 0; dx < seaHorse[0].size(); ++dx)
            if (seaHorse[dy][dx] == '#')
               if (transformAndGet(image, t, x + dx, y + dy) == '.')
                  return false;
//      cout << x << " " << y << endl;
      for (int dy = 0; dy < seaHorse.size(); ++dy)
         for (int dx = 0; dx < seaHorse[0].size(); ++dx)
            if (seaHorse[dy][dx] == '#')
               transformAndGet(image, t, x + dx, y + dy) = 'O';
      return true;
   }

   void processImage(vector<string> &image) {
      bool found = false;
      for (int t = 0; !found; ++t)
         for (int y = 0; y < image.size() - seaHorse.size(); ++y)
            for (int x = 0; x < image[0].size() - seaHorse[0].size(); ++x)
               if (matchAndMaskSeaMonster(image, t, x, y))
                  found = true;

      int star2 = 0;
      for (const auto &s : image)
         star2 += count(s.begin(), s.end(), '#');
      cout << "Day 20 star 2 = " << star2 << "\n";
   }
   vector<vector<string>> tiles;
   vector<unsigned long long> tileIDs;
   vector<bool> tilesUsed;
   vector<vector<Tile>> grid;
};

void day20() {
   ImageProcessor("../day20.txt");
}
