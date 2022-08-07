#include <tcframe/spec.hpp>
using namespace tcframe;
using namespace std;

#define MAXN 100

class ProblemSpec : public BaseProblemSpec {
protected:
	int t;
	int n;
	vector<string> g;
	int ans;

	void InputFormat() {
		LINE(n);
		LINES(g) % SIZE(n);
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
		CONS(correctGridSize(g, n));
		CONS(validCells(g));
	}

private:
	bool correctGridSize(vector<string> g, int n) {
		if (g.size() != n) return false;
		for (auto s : g) {
			if (s.size() != n) return false;
		}
		return true;
	}

	bool validCells(vector<string> g) {
		for (auto s : g) {
			for (auto c : s) {
				if (c != '+' && c != '.') return false;
			}
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
		g.clear();
	}

	void TestGroup1() {
		CASE(n = 4, g = {"...+", "+.+.", "....", "+..."});
	}

	void TestGroup2() {
		for (int i=0; i<9; i++) {
			CASE(n = rnd.nextInt(1, MAXN), plainGrid(g, n));
		}
		CASE(n = MAXN, plainGrid(g, n));
	}

	void TestGroup3() {
		for (int i=0; i<2; i++) {
			CASE(n = rnd.nextInt(1, MAXN), randomGrid(g, n, 10));
		}
		for (int i=0; i<2; i++) {
			CASE(n = rnd.nextInt(1, MAXN), randomGrid(g, n, 50));
		}
		CASE(n = rnd.nextInt(1, MAXN), randomGrid(g, n, 100));
		for (int i=0; i<2; i++) {
			CASE(n = MAXN, randomGrid(g, n, 10));
		}
		for (int i=0; i<2; i++) {
			CASE(n = MAXN, randomGrid(g, n, 50));
		}
		CASE(n = MAXN, randomGrid(g, n, 100));
	}

private:
	void plainGrid(vector<string>& g, int n) {
		g.resize(n);
		for (int i=0; i<n; i++) {
			g[i] = "";
			for (int j=0; j<n; j++) g[i].push_back('.');
		}
	}

	void randomGrid(vector<string>& g, int n, int ratioplus) {
		g.resize(n);
		for (int i=0; i<n; i++) {
			g[i] = "";
			for (int j=0; j<n; j++) {
				if ((i == 0 && j == 0) || (i == n-1 && j == n-1)) g[i].push_back('.');
				else {
					int gacha = rnd.nextInt(1, 100);
					if (gacha <= ratioplus) g[i].push_back('+');
					else g[i].push_back('.');
				}
			}
		}
	}
};