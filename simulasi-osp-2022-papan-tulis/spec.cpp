#include <tcframe/spec.hpp>
using namespace tcframe;
using namespace std;

const int minx = 2;
const int maxx = 1000000000;
const int miny = 1;
const int maxy = 1000000000;


class ProblemSpec : public BaseProblemSpec {
protected:
    int t;
    vector<int> x, y;
    vector<int> ans;

    void InputFormat() {
        LINE(t);
        LINES(x, y) % SIZE(t);
    }

    void OutputFormat() {
        LINES(ans) % SIZE(t);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(eachElementBetween(x, minx, maxx));
        CONS(eachElementBetween(y, miny, maxy));
    }

private:
    bool eachElementBetween(const vector<int>& x, int mn, int mx) {
        for (int a : x) {
            if (a < mn || a > mx) return false;
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    // void SampleTestCase1() {
    //     Input({
    //     });
    //     Output({
    //     });
    // }

    void BeforeTestCase(){
        x.clear();
        y.clear();
        ans.clear();
    }

    void TestCases() {
        CASE(t = 4, x = {2, 3, 2, 21}, y = {3, 11, 1, 3});
        CASE(t = 10, randomArrayWithHead(t, x, minx, 1000, {2, 3, 4, 5}), randomArrayWithHead(t, y, miny, 1000, {996, 997, 998, 999}));
        CASE(t = 10, randomArrayWithHead(t, x, minx, maxx, {2, 3, 4, 5}), randomArrayWithHead(t, y, miny, maxy, {maxy, maxy-4, maxy-3, maxy-2}));
    }

private:
    void randomArrayWithHead(int n, vector<int>& a, int mn, int mx, vector<int> head) {
        for (int x : head) a.push_back(x);
        for (int i=0; i<n-(int)head.size(); i++) a.push_back(rnd.nextInt(mn, mx));
    }
};