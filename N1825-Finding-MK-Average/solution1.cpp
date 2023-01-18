class MKAverage {
private:
    int m, k;
    queue<int> q;
    multiset<int> s1, s2, s3;
    long long sum2;
public:
    MKAverage(int m, int k) : m(m), k(k) {
        sum2 = 0;
    }

    void addElement(int num) {
        q.push(num);
        if (q.size() <= m) {
            s2.insert(num);
            sum2 += num;
            if (q.size() == m) {
                while (s1.size() < k) {
                    s1.insert(*s2.begin());
                    sum2 -= *s2.begin();
                    s2.erase(s2.begin());
                }
                while (s3.size() < k) {
                    s3.insert(*s2.rbegin());
                    sum2 -= *s2.rbegin();
                    s2.erase(prev(s2.end()));
                }
            }
            return;
        }

        if (num < *s1.rbegin()) {
            s1.insert(num);
            s2.insert(*s1.rbegin());
            sum2 += *s1.rbegin();
            s1.erase(prev(s1.end()));
        } else if (num > *s3.begin()) {
            s3.insert(num);
            s2.insert(*s3.begin());
            sum2 += *s3.begin();
            s3.erase(s3.begin());
        } else {
            s2.insert(num);
            sum2 += num;
        }

        int x = q.front();
        q.pop();
        if (s1.count(x) > 0) {
            s1.erase(s1.find(x));
            s1.insert(*s2.begin());
            sum2 -= *s2.begin();
            s2.erase(s2.begin());
        } else if (s3.count(x) > 0) {
            s3.erase(s3.find(x));
            s3.insert(*s2.rbegin());
            sum2 -= *s2.rbegin();
            s2.erase(prev(s2.end()));
        } else {
            s2.erase(s2.find(x));
            sum2 -= x;
        }
    }

    int calculateMKAverage() {
        if (q.size() < m) {
            return -1;
        }
        return sum2 / (m - 2 * k);
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */
