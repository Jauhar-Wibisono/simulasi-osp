#include <tcframe/spec.hpp>
using namespace tcframe;
using namespace std;

const int mina = 1;
const int maxa = 1000000000;


class ProblemSpec : public BaseProblemSpec {
protected:
    int t;
    vector<int> a, b, c, d;
    vector<int> ans;

    void InputFormat() {
        LINE(t);
        LINES(a, b, c, d) % SIZE(t);
    }

    void OutputFormat() {
        LINES(ans) % SIZE(t);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(eachElementBetween(a, mina, maxa));
        CONS(eachElementBetween(b, mina, maxa));
        CONS(eachElementBetween(c, mina, maxa));
        CONS(eachElementBetween(d, mina, maxa));
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
        a.clear();
        b.clear();
        c.clear();
        d.clear();
        ans.clear();
    }

    void TestCases() {
        // TODO: open subtask
        CASE(
            t = 3,
            a = {1, 9, 2},
            b = {3, 8, 2},
            c = {4, 7, 2},
            d = {10, 6, 3}
        );
        CASE(
            t = 15, 
            randomArrayWithHead(t, a, mina, maxa, {}), 
            b = a,
            c = a,
            randomArrayWithHead(t, d, mina, maxa, {})
        );
        CASE(
            t = 15, 
            randomArrayWithHead(t, a, mina, maxa, {1, maxa/2, 1}), 
            randomArrayWithHead(t, b, mina, maxa, {maxa/2, 1, maxa}),
            randomArrayWithHead(t, c, mina, maxa, {maxa/2, maxa, maxa/2}),
            randomArrayWithHead(t, d, mina, maxa, {maxa, maxa/2, maxa/2})
        );
    }

private:
    void randomArrayWithHead(int n, vector<int>& a, int mn, int mx, vector<int> head) {
        for (int x : head) a.push_back(x);
        for (int i=0; i<n-(int)head.size(); i++) a.push_back(rnd.nextInt(mn, mx));
    }
};