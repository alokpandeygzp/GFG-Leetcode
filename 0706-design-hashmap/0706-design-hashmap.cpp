class MyHashMap {
public:
    int arr[1000001];
    MyHashMap() {
        fill(arr,arr+1000001,INT_MIN);
    }
    
    void put(int key, int value) {
        arr[key]=value;
    }
    
    int get(int key) {
        if(arr[key]==INT_MIN)
            return -1;
        return arr[key];
    }
    
    void remove(int key) {
        arr[key]=INT_MIN;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */