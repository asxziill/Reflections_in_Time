namespace MemP {
  template <class T>
  struct P
  {
    static std::vector<T> info;
    static std::vector<int> sta;

    int p = 0;

    P (int _p = 0) : p(_p) {}

    static void init() {
      info.clear();
      info.push_back(T());
      sta.clear();
    }

    static P newNode() {
      if (!sta.empty()) {
        int x = sta.back();
        sta.pop_back();
        info[x] = T();
        return P(x);
      }
      info.push_back(T());
      return P(info.size() - 1);
    }

    static void del(const P &t) {
      sta.push_back(t.p);
    }

    static P clone(const P &t) {
      if (!sta.empty()) {
        int x = sta.back();
        sta.pop_back();
        info[x] = info[t.p];
        return P(x);
      }
      info.push_back(info[t.p]);
      return P(info.size() - 1);
    }

    T *operator->() {
      return &(info[p]);
    }

    bool empty() {
      return p == 0;
    }
  };

  template <class T> 
  std::vector<T> P<T>::info(1, T());

  template <class T> 
  std::vector<int> P<T>::sta;
}
