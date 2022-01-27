#include <bits/stdc++.h>
using namespace std;

// A Cat is a pair of <level, time>
typedef pair<int, int> Cat;

#define fi first
#define se second

int n, op, level, inc;
string name;

struct CatComparator {
    bool operator()(const Cat& cat1, const Cat& cat2) const {
        // Sort Cats by level descending, then by time ascending
        return cat1.fi != cat2.fi ? cat1.fi > cat2.fi : cat1.se < cat2.se;
    }
};

map<Cat, string, CatComparator> cat_to_name;  // Cat -> name
unordered_map<string, Cat> name_to_cat;       // name -> Cat

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    // Read input
    cin >> n;
    for (int time = 0; time < n; time++) {
        cin >> op;
        if (op == 0) {
            // Arrive at clinic
            cin >> name >> level;

            // Create a new entry in both containers
            Cat cat = {level, time};  // O(1)
            cat_to_name[cat] = name;  // O(logn)
            name_to_cat[name] = cat;  // O(1)
        } else if (op == 1) {
            // Update infection level
            cin >> name >> inc;

            // Use unordered_map to retrieve Cat by name
            Cat& cat = name_to_cat[name];  // O(1)
            // Remove the Cat entry from map
            cat_to_name.erase(cat);  // O(logn)
            // Increment infection level
            // At line 45, Cat is a reference to name_to_cat's value,
            // thus name_to_cat's value is updated by line 51
            cat.fi += inc;
            // Insert the updated cat into map
            // We have to delete the old Cat->name entry from cat_to_name and
            // insert a new one because Cat is a key in cat_to_name, not a value.
            cat_to_name[cat] = name;  // O(logn)
        } else if (op == 2) {
            // Leave clinic
            cin >> name;

            Cat& cat = name_to_cat[name];  // O(1)
            // Remove Cat entry from both containers
            cat_to_name.erase(cat);   // O(logn)
            name_to_cat.erase(name);  // O(1), not necessary
        } else {
            // Output highest infection cat
            if (cat_to_name.empty())
                cout << "The clinic is empty\n";
            else
                cout << cat_to_name.begin()->se << "\n";  // O(1)
        }
    }
}