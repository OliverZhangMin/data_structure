class MyCircularDeque {
public:
    int m_iAllSize = -1;
    vector<int> m_vecQueue;
    int m_iFront=0;
    int m_iLast=1;
    MyCircularDeque(int k) {
        m_iAllSize = k+1;
        m_vecQueue.resize(m_iAllSize);
    }
    
    bool insertFront(int value) {
        if(m_iFront == m_iLast)
            return false;
        m_vecQueue[m_iFront] = value;
        if(m_iFront==0)
            m_iFront = m_iAllSize-1;
        else
            --m_iFront;
        return true;
    }
    
    bool insertLast(int value) {
        if(m_iFront == m_iLast)
            return false;
        m_vecQueue[m_iLast] = value;
        if(m_iLast == (m_iAllSize-1))
            m_iLast = 0;
        else
            ++m_iLast;
            return true;
    }
    
    bool deleteFront() {
        int dst_index= (m_iFront+1)%m_iAllSize;
        if(dst_index == m_iLast)
            return false;
        m_iFront = dst_index;
        return true;
    }
    
    bool deleteLast() {
         int dst_index= m_iLast==0?m_iAllSize-1:--m_iLast;
        if(dst_index == m_iFront)
            return false;
        m_iLast = dst_index;
        return true;
    }
    
    int getFront() {
        
        if(isEmpty())
            return -1;
        else
        {
            int dst_index = m_iFront==m_iAllSize-1?0:m_iFront+1;
            return m_vecQueue[dst_index];
        }
    }
    
    int getRear() {
        if(isEmpty())
            return -1;
        else{
            int dst_index = m_iLast==0?m_iAllSize-1:m_iLast-1;
            return m_vecQueue[dst_index];
        }

    }
    
    bool isEmpty() {
        int diff = ((m_iFront+1)%m_iAllSize) - m_iLast ;
        if(diff == 0)
            return true;
        else
            return false;
    }
    
    bool isFull() {
        return m_iFront == m_iLast;
    }
   
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */