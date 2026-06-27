template <typename T>
class DList
{
public:
    // 默认 构造
    Dlist() = default;
    // 拷贝 构造
    Dlist(const Dlist &other) noexcept
    {
        ListNode *curr = other.head;
        while (curr)
        {
            push_back(curr->val);
            curr = curr->next;
        }
    }
    // 拷贝 赋值
    Dlist &operator=(const Dlist &other) noexcept
    {
        if (this != &other)
        {
            clear();
            ListNode *curr = other.head;
            while (curr)
            {
                push_back(curr->val);
                curr = curr->next;
            }
        }
        return *this;
    }
    // 移动 构造
    Dlist(Dlist &&other) noexcept : head(other.head), tail(other.tail), size(other.size)
    {
        other.head = nullptr;
        other.tail = nullptr;
        other.size = nullptr;
    }
    // 移动 赋值
    Dlist &operator=(Dlist &&other) noexcept
    {
        if (this != &other)
        {
            head = other.head;
            tail = other.tail;
            size = other.size;
            other.head = nullptr;
            other.tail = nullptr;
            other.size = 0;
        }
        return *this;
    }
    // 析构
    ~Dlist()
    {
        clear();
    }
    void push_front(const T &val)
    {
        ListNode *curr = new Node(val);
        if (!head)
        {
            head = curr;
            tail = curr;
        }
        else
        {
            curr->next = head;
            head->prev = curr;
            head = curr;
        }
        ++size;
    }
    void push_back(const T &val)
    {
        ListNode *curr = new Node(val);
        if (!tail)
        {
            head = curr;
            tail = curr;
        }
        else
        {
            curr->prev = tail;
            tail->next = curr;
            tail = curr;
        }
        ++size;
    }
    void pop_front()
    {
        if (size <= 0)
        {
            return;
        }
        ListNode *tmp = head;
        head = head->next;
        if (head)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr;
        }
        delete tmp;
        --size;
    }
    void pop_back()
    {
        if (size <= 0)
        {
            return;
        }
        ListNode *tmp = tail;
        tail = tail->prev;
        if (tail)
        {
            tail->next = nullptr;
        }
        else
        {
            head = nullptr;
        }
        delete tmp;
        --size;
    }
    void erase(ListNode *curr)
    {
        if (curr = nullptr)
        {
                }
    }
    size_t size()
    {
        return size;
    }
    bool empty()
    {
        return head == nullptr && tail == nullptr;
    }

private:
    void clear()
    {
        for (; head->next; head = head->next)
        {
            ListNode *curr = head;
            delete curr;
        }
        tail = nullptr;
        size = 0;
    }
    struct ListNode
    {
        T val;
        ListNode *prev;
        ListNode *next;
        ListNode(const T &value) : val(value), prev(nullptr), next(nullptr) {}
        ListNode(T &&value) : val(std::move(value)), prev(nullptr), next(nullptr) {}
    };
    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    size_t size = 0;
};
