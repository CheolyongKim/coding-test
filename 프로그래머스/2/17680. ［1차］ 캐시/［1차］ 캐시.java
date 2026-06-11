import java.util.*;
class Solution {
    public int solution(int cacheSize, String[] cities) {
        int answer = 0;
        if (cacheSize==0) return 5*(cities.length);
        
        LinkedList<String> cache = new LinkedList<>();
        for (String c : cities){
            c = c.toUpperCase();
                if (cache.contains(c)){
                    cache.removeFirstOccurrence(c);
                    answer++;
                    if(cache.size() < cacheSize) cache.add(c);
                }else{
                    if (0<cache.size() && cache.size()==cacheSize) cache.remove(0);
                    answer += 5;
                    if(cache.size() < cacheSize) cache.add(c);
                }
        }
        
        return answer;
    }
}