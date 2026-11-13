// LeetCode 641 - Design Circular Deque
// Question: Design a circular double-ended queue supporting insertion and
// deletion at both ends, getFront, getRear, isEmpty, and isFull.
// Approach: Fixed-size array with front/rear indices and modulo arithmetic.
// Each operation: O(1) | Space: O(k)

class MyCircularDeque {
private:
    vector<int> data;
    int frontIndex;
    int rearIndex;
    int count;
    int capacity;

public:
    MyCircularDeque(int k)
        : data(k), frontIndex(0), rearIndex(-1), count(0), capacity(k) {}

    bool insertFront(int value) {
        if (isFull()) return false;
        frontIndex = (frontIndex - 1 + capacity) % capacity;
        data[frontIndex] = value;
        if (count == 0) rearIndex = frontIndex;
        ++count;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        rearIndex = (rearIndex + 1) % capacity;
        data[rearIndex] = value;
        if (count == 0) frontIndex = rearIndex;
        ++count;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        frontIndex = (frontIndex + 1) % capacity;
        --count;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        rearIndex = (rearIndex - 1 + capacity) % capacity;
        --count;
        return true;
    }

    int getFront() {
        return isEmpty() ? -1 : data[frontIndex];
    }

    int getRear() {
        return isEmpty() ? -1 : data[rearIndex];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }
};
