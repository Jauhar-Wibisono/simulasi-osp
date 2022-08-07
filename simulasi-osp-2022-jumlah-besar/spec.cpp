#include <tcframe/spec.hpp>
using namespace tcframe;
using namespace std;

#define MAXN 200000
#define MAXA 1000000000

class ProblemSpec : public BaseProblemSpec {
protected:
	int t;
	int n, x;
	vector<int> a;
	long long ans;

	void InputFormat() {
		LINE(n, x);
		LINE(a % SIZE(n));
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
		CONS(eachElementBetween(a, 1, MAXA));
	}

private:
	bool eachElementBetween(const vector<int>& a, int mn, int mx) {
		for (int x : a) {
			if (x < mn || x > mx) return false;
		}
		return true;
	}
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
	// void SampleTestCase1() {
	// 	Input({
	// 		"3",
	// 		"-3 4",
	// 		"4 9",
	// 		"5 8"
	// 	});
	// 	Output({
	// 		"1"
	// 	});
	// }

	// void SampleTestCase2() {
	// 	Input({
	// 		"1",
	// 		"0 0"
	// 	});
	// 	Output({
	// 		"0"
	// 	});
	// }

	void BeforeTestCase(){
		a.clear();
	}

	void TestGroup1() {
		CASE(n = 8, x = 4, a = {1, 1, 1, 1, 1, 1, 1, 1});
		CASE(n = 5, x = 21, a = {5, 3, 9, 1, 10});

	}

	void TestGroup2() {
		for (int i=0; i<10; i++) {
			CASE(n = rnd.nextInt(100, 500), x = rnd.nextInt(1, MAXA), randomArray(a, n, 1, MAXA));
		}
	}

	void TestGroup3() {
		for (int i=0; i<10; i++) {
			CASE(n = rnd.nextInt(MAXN/2, MAXN), x = rnd.nextInt(1, MAXA), randomArray(a, n, 1, MAXA));
		}	
	}

private:
	void randomArray(vector<int>& a, int n, int mn, int mx){
		for (int i=0; i<n; i++) a.push_back(rnd.nextInt(mn, mx));
	}
};