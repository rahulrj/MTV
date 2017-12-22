class WordDistance {

    public String words[];
    HashMap<String,ArrayList<Integer>>map=new HashMap<>();
    
    public WordDistance(String[] words) {
        this.words=words;

        int len=words.length;
        
        for(int i=0;i<len;i++){
            ArrayList<Integer>list=map.get(words[i]);
            if(list==null){
                list=new ArrayList<>();
                list.add(i);
            }
            else{
                list.add(i);
            }
            map.put(words[i],list);
        }
    }
    
    public int shortest(String word1, String word2) {
         List<Integer>first=map.get(word1);
         List<Integer>second=map.get(word2);
        // int len=words.length;

        
        int size=first.size();
        int size2=second.size();
        int min=Integer.MAX_VALUE;
        for(int j=0;j<size;j++){           
            for(int k=0;k<size2;k++){
                if(Math.abs(first.get(j)-second.get(k))<min){
                    min=Math.abs(first.get(j)-second.get(k));
                }
            }
        }
        
       return min; 
        
    }
}

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */