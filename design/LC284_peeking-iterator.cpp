/*
 * class Iterator {
 * public:
 *     Iterator(const vector<int>& nums);
 *     Iterator(const Iterator& iter);
 *     int next();
 *     bool hasNext() const;
 * private:
 *     struct Data;
 *     Data* data;
 * };
 *
 *
 * */
class PeekingIterator : public Iterator {
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        flag = Iterator::hasNext();
        if (flag) {
            nextElement = Iterator::next();
        }
    }
    
    int peek() {
        return nextElement;
    }
    
    int next() {
        int ret = nextElement;
        flag = Iterator::hasNext();
        if (flag) {
            nextElement = Iterator::next();
        }
        return ret;
    }
    
    bool hasNext() const {
        return flag;
    }
private:
    int nextElement;
    bool flag;
};
