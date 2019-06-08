#ifndef CPP_NODE_H
#define CPP_NODE_H

template <typename T>
class Node
{
public:
    Node()= delete;

    Node(const T& data, const Node* const next) :
        data_(data),
        next_(next){}

    explicit Node(const T& data) : Node(data, nullptr){}

    T& get_data() const
    {
        return data_;
    }

    const Node* const get_next() const
    {
        return next_;
    }

private:
    T data_;
    Node* next_ = nullptr;
};

#endif //CPP_NODE_H
