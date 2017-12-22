class TwoSum {

    
    private HashMap<Integer,Integer>map;
    /** Initialize your data structure here. */
    public TwoSum() {
        map=new HashMap<>();
    }
    
    /** Add the number to an internal data structure.. */
    public void add(int number) {
        map.put(number,map.getOrDefault(number,0)+1);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    public boolean find(int value) {
        Iterator it=map.entrySet().iterator();
        while(it.hasNext()){
            Map.Entry entry =(Map.Entry)it.next();
            int key=(Integer)entry.getKey();
            int rem=value- key;
            //System.out.println(rem);
            if(rem==key){
                //System.out.println("Val"+(Integer)entry.getValue());
                if((Integer)entry.getValue()>1){
                    return true;
                }
            }
            else{
                int val=map.getOrDefault(rem,0);
                if(val>0){
                    return true;
                }
                //return map.get(rem)!=null;
            }
        
        }
        return false;
    }
}

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * boolean param_2 = obj.find(value);
 */