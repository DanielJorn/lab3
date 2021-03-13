template<class L, class R>
class Pair {
public:
    L left;
    R right;

    Pair() {}

    Pair(L l, R r) {
        left = l;
        right = r;
    }
};