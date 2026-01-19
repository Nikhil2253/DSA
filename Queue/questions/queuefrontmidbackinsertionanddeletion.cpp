class FrontMiddleBackQueue {
private:
    deque<int> q;

public:
    FrontMiddleBackQueue() {}

    void pushFront(int val) {
        q.push_front(val);
    }

    void pushMiddle(int val) {
        int middle = q.size() / 2;
        stack<int> st;

        for (int i = 0; i < middle; i++) {
            st.push(q.front());
            q.pop_front();
        }

        q.push_front(val);

        while (!st.empty()) {
            q.push_front(st.top());
            st.pop();
        }
    }

    void pushBack(int val) {
        q.push_back(val);
    }

    int popFront() {
        if (q.empty()) return -1;
        int val = q.front();
        q.pop_front();
        return val;
    }

    int popMiddle() {
        if (q.empty()) return -1;

        int middle = (q.size() - 1) / 2;
        stack<int> st;

        for (int i = 0; i < middle; i++) {
            st.push(q.front());
            q.pop_front();
        }

        int val = q.front();
        q.pop_front();

        while (!st.empty()) {
            q.push_front(st.top());
            st.pop();
        }

        return val;
    }

    int popBack() {
        if (q.empty()) return -1;
        int val = q.back();
        q.pop_back();
        return val;
    }
};
