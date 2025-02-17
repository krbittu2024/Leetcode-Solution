class Solution {
    public:
         void backtrack(string &tiles, unordered_set<string> &result, string current) {
            if (!current.empty()) {
                result.insert(current); 
            }
            
          
            for (int i = 0; i < tiles.size(); ++i) {
                if (tiles[i] == '#' || (i > 0 && tiles[i] == tiles[i - 1])) {
                    continue; 
                }
                
                char temp = tiles[i];
                tiles[i] = '#'; 
                backtrack(tiles, result, current + temp); 
                tiles[i] = temp; 
            }
        }
    
        int numTilePossibilities(string tiles) {
            unordered_set<string> result;
            sort(tiles.begin(), tiles.end()); 
            backtrack(tiles, result, "");
            return result.size(); 
        }
    };
    