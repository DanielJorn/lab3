template<class L, class R>
class Pair;

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

    bool operator==(const Pair &anotherPair) const;
    bool operator!=(const Pair &anotherPair) const;

};

template<class L, class R>
bool Pair<L, R>::operator==(const Pair &anotherPair) const {
    bool leftEqual = this->left == anotherPair.left;
    bool rightEqual = this->right == anotherPair.right;
    return leftEqual && rightEqual;
}
template<class L, class R>
bool Pair<L, R>::operator!=(const Pair &anotherPair) const {
    return !operator==(anotherPair);
}
