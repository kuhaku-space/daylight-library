
#define PROBLEM \
	"https://judge.yosupo.jp/problem/queue_operate_all_composite"
#include <atcoder/all>
#include "daylight/base.hpp"
#include "daylight/structure/swag.hpp"
using namespace atcoder;
using mint = modint998244353;

int main() {
	int Q;
	cin >> Q;
	using P = pair<mint, mint>;
	FoldableQueue<P> swag(
		[](P a, P b) -> P {
			return { a.first * b.first,
					 a.second * b.first + b.second };
		},
		{ 1, 0 });
	while(Q--) {
		int t;
		cin >> t;
		if(t == 0) {
			int a, b;
			cin >> a >> b;
			swag.push({ a, b });
		} else if(t == 1) {
			swag.pop();
		} else {
			int x;
			cin >> x;
			auto f = swag.fold();
			cout << (f.first * x + f.second).val() << endl;
		}
	}
}