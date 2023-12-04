// O(1)
// O(n)
class RandomizedCollection {
	public:
		unordered_map<int, unordered_set<int>> idx;
		vector<int> nums;

		/** Initialize your data structure here. */
		RandomizedCollection() {

		}

		/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
		bool insert(int val) {
			nums.push_back(val);
			idx[val].insert(nums.size() - 1);  // insert new index into the val set
			return idx[val].size() == 1;   // val index more than one
		}

		/** Removes a value from the collection. Returns true if the collection contained the specified element. */
		bool remove(int val) {
			// check duplicate
			if (idx.find(val) == idx.end()) {
				return false;
			}
			// get val index, replace with the last element
			int i = *(idx[val].begin());
			nums[i] = nums.back();
			idx[val].erase(i);
			idx[nums[i]].erase(nums.size() - 1);

			// re-organize the index of nums[i]
			if (i < nums.size() - 1) {
				idx[nums[i]].insert(i);
			}

 			// no index, delete
			if (idx[val].size() == 0) {
				idx.erase(val);
			}
			nums.pop_back();
			return true;
		}

		/** Get a random element from the collection. */
		int getRandom() {
			return nums[rand() % nums.size()];
		}
};
