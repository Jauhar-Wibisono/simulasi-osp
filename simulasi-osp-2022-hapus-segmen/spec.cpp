#include <tcframe/spec.hpp>
using namespace tcframe;
using namespace std;

#define MAXN 20000
#define MAXA 1000000000

class ProblemSpec : public BaseProblemSpec {
protected:
	int t;
	int n;
	vector<int> l, r;
	int ans;

	void InputFormat() {
		LINE(n);
		LINES(l, r) % SIZE(n);
	}

	void OutputFormat() {
		LINE(ans);
	}

	void GradingConfig() {
		TimeLimit(1);
		MemoryLimit(256);
	}

	void MultipleTestCasesConfig() {
		Counter(t);
	}

	void MultipleTestCasesConstraints() {
        CONS(1 <= t && t <= 20);
    }

	void Constraints() {
		CONS(1 <= n && n <= MAXN);
		CONS(validSeg(l, r, -MAXA, MAXA));
	}

private:
	bool validSeg(vector<int> l, vector<int> r, int mn, int mx){
		if (l.size() != r.size()) return false;
		for (int i=0; i<(int)l.size(); i++){
			if (l[i] < mn || l[i] > r[i] || r[i] > mx) return false;
		}
		return true;
	}
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
	void SampleTestCase1() {
		Input({
			"3",
			"-3 4",
			"4 9",
			"5 8"
		});
		Output({
			"1"
		});
	}

	void SampleTestCase2() {
		Input({
			"1",
			"0 0"
		});
		Output({
			"0"
		});
	}

	void BeforeTestCase(){
		l.clear();
		r.clear();
	}

	void TestGroup1() {
		CASE(
			n = 12,
			l = {1, -8, -8, 1, 5, 4, -8, -7, 1, 1, -7, -7},
			r = {8, -2, -4, 8, 9, 6, -4, -2, 5, 6, 10, 6}
		);
	}

	void TestGroup2() {
		for (int i=0; i<5; i++){
			int mn = rnd.nextInt(-10, 10);
			int mx = rnd.nextInt(-10, 10);
			if (mn > mx) swap(mn, mx);
			CASE(n = 10, randomSeg(n, l, r, mn, mx));
		}
		for (int i=0; i<5; i++){
			int mn = rnd.nextInt(-MAXA, MAXA);
			int mx = rnd.nextInt(-MAXA, MAXA);
			if (mn > mx) swap(mn, mx);
			CASE(n = 10, randomSeg(n, l, r, mn, mx));
		}
	}

	void TestGroup3() {
		for (int i=0; i<10; i++){
			int mn = rnd.nextInt(-MAXA, MAXA);
			int mx = rnd.nextInt(-MAXA, MAXA);
			if (mn > mx) swap(mn, mx);
			CASE(n = MAXN/10, randomSeg(n, l, r, mn, mx));
		}
	}

private:
	void randomSeg(int n, vector<int> &l, vector<int> &r, int mn, int mx){
		for (int i=0; i<n; i++){
			int ll = rnd.nextInt(mn, mx);
			int rr = rnd.nextInt(mn, mx);
			if (ll > rr) swap(ll, rr);
			l.push_back(ll);
			r.push_back(rr);
		}
	}
};