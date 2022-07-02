//https://leetcode.com/problems/snapshot-array/

class SnapshotArray {
public:
    int snap_id = 0;
    unordered_map<int,map<int,int>> m;
    SnapshotArray(int length) {
        
    }
    
    void set(int index, int val) {
        m[index][snap_id] = val;
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        auto it= m[index].upper_bound(snap_id);
        
        return it== begin(m[index])? 0:prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
