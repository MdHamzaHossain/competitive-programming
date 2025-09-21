// TODO
class MovieRentingSystem
{
private:
    unordered_map<int, set<pair<int, int>>> unrented;
    map<pair<int, int>, int> shopAndMovieToPrice;
    set<tuple<int, int, int>> rented;

public:
    /**
     * Initialize the movie renting system.
     * @param n Number of shops
     * @param entries List of [shop, movie, price] entries
     */
    MovieRentingSystem(int n, vector<vector<int>> &entries)
    {

        for (const auto &entry : entries)
        {
            int shop = entry[0];
            int movie = entry[1];
            int price = entry[2];

            unrented[movie].insert({price, shop});

            shopAndMovieToPrice[{shop, movie}] = price;
        }
    }

    /**
     * Search for the 5 cheapest shops that have an unrented copy of the given movie.
     * @param movie The movie ID to search for
     * @return List of up to 5 shop IDs with cheapest prices
     */
    vector<int> search(int movie)
    {
        vector<int> result;

        if (unrented.find(movie) != unrented.end())
        {

            int count = 0;
            for (const auto &[price, shop] : unrented[movie])
            {
                if (count >= 5)
                    break;
                result.push_back(shop);
                count++;
            }
        }

        return result;
    }

    /**
     * Rent a movie from a specific shop.
     * @param shop The shop ID
     * @param movie The movie ID to rent
     */
    void rent(int shop, int movie)
    {

        int price = shopAndMovieToPrice[{shop, movie}];
        unrented[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }

    /**
     * Return a rented movie to a specific shop.
     * @param shop The shop ID
     * @param movie The movie ID to return
     */
    void drop(int shop, int movie)
    {
        int price = shopAndMovieToPrice[{shop, movie}];
        unrented[movie].insert({price, shop});
        rented.erase({price, shop, movie});
    }

    /**
     * Get the 5 cheapest rented movies.
     * @return List of up to 5 [shop_id, movie_id] pairs
     */
    vector<vector<int>> report()
    {
        vector<vector<int>> result;

        int count = 0;
        for (const auto &[price, shop, movie] : rented)
        {
            if (count >= 5)
                break;
            result.push_back({shop, movie});
            count++;
        }

        return result;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */