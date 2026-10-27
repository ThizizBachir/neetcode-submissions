struct Range {
public:
    int start, end;
    Range(int s, int e) : start(s), end(e) {}

    int length() const {
        return this->end - this->start + 1;
    }

};
class Solution {
public:

    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, shared_ptr<Range>> ranges;
        unordered_set<int> visited;
        int lenmax = 0;
        for (int x : nums) {
            if (visited.count(x) == 1) continue;
            visited.insert(x);
            bool leftRangeExist = ranges.count(x - 1) == 1;
            bool rightRangeExist = ranges.count(x + 1) == 1;
            if (leftRangeExist && rightRangeExist) {
                auto r1 = ranges[x - 1];
                auto r2 = ranges[x + 1];
                ranges.erase(x - 1);
                ranges.erase(x + 1);
                auto r = make_shared<Range>(r1->start, r2->end);
                ranges[r->start] = r;
                ranges[r->end] = r;
                lenmax = max(lenmax, ranges[r->start]->length());
            }
            else if (leftRangeExist) {
                auto r = ranges[x - 1];

                if(r->start != r->end) ranges.erase(x - 1);
                ranges[x] = r;
                r->end = x;
                lenmax = max(lenmax, r->length());
            }
            else if (rightRangeExist) {
                auto r = ranges[x + 1];
                if (r->start != r->end) ranges.erase(x + 1);
                ranges[x] = r;
                r->start = x;
                lenmax = max(lenmax, r->length());
            }
            else {
                auto r = make_shared<Range>(x, x);
                ranges[x] = r;
                lenmax = max(lenmax, 1);
                
            }
            cout <<"new iteration"<< x << leftRangeExist<<endl;

            for (const auto& [key, value] : ranges) {
                cout << "-" << key << ":" << value->start<<":::"<<value->end<<endl;
            }
        }
        return lenmax;


    }
};