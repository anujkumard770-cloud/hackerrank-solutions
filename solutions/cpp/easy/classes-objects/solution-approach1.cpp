// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/classes-objects/problem?isFullScreen=true
// Problem     Classes and Objects
// Difficulty  Easy
// Subdomain   Classes
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-09-18, 06:07 p.m.
// ──────────────────────────────────────────────────



// Write your Student class here
class Student{
    public:
      int scores[5];
      
      
      void input(){
        for(int i=0; i<5; i++){
            cin>>scores[i];
        }
      }
      
      int calculateTotalScore(){
        int total=0;
        
        for(int i=0; i<5; i++){
            total += scores[i];
        }
        
        return total;
      }
};

