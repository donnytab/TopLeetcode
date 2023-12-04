Class RandomizedSet {
private:
    unordered_map<int, int> indices;
    vector<int> nums;

public:
    RandomizedSet() {
        srand((unsigned)time(NULL));
    }

    bool insert(int val) {
        if (indices.count(val)) {
            return false;
        }

        int iIndex = nums.size();
        nums.emplace_back(val);
        indices[iIndex] = val;

        return true;
    }

    bool remove(int val) {
        if (!indices.count(val)) {
            return false;
        }

        int iIndex = indices[val];
        int iLastElem = nums.back();

        // replace with last element
        nums[iIndex] = iLastElem;
        indices[iLastElem] = iIndex;

        nums.pop_back();  // delete
        indices.erase(val);

        return true;
    }

    int getRandom() {
        int iRandIdx = rand()%nums.size();
        return nums.at(iRandIdx);
    }
}；
