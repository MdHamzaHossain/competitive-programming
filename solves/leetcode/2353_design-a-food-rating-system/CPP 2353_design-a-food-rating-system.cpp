// TODO
class FoodRatings
{
public:
    unordered_map<string, pair<int, string>> foodInfo;
    unordered_map<string, set<pair<int, string>>> cuisineToFoodSet;

    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
    {
        for (int i = 0; i < foods.size(); ++i)
        {
            cuisineToFoodSet[cuisines[i]].insert({-ratings[i], foods[i]});
            foodInfo[foods[i]] = {ratings[i], cuisines[i]};
        }
    }

    void changeRating(string food, int newRating)
    {
        auto [prev, cuisine] = foodInfo[food];

        foodInfo[food] = {newRating, cuisine};
        cuisineToFoodSet[cuisine].erase({-prev, food});
        cuisineToFoodSet[cuisine].insert({-newRating, food});
    }

    string highestRated(string cuisine)
    {
        return cuisineToFoodSet[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */