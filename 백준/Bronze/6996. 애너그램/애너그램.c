#include <stdio.h>
#include <string.h>

int main() {
    int n;
    int check1[26]={0,}, check2[26]={0,};
    int l1, l2, flag;
    char s1[101], s2[101];
    
    scanf("%d",&n);
    
    for(int i=0;i<n;i++){
        scanf("%s %s",s1, s2);
        l1=strlen(s1);
        l2=strlen(s2);
        if(l1!=l2){
            printf("%s & %s are NOT anagrams.\n",s1, s2);
            continue;
        }
        for(int j=0;j<l1;j++){
            check1[s1[j]-'a']++;
        }
        for(int j=0;j<l2;j++){
            check2[s2[j]-'a']++;
        }
        for(int j=0;j<26;j++){
            if(check1[j]!=check2[j]){
                flag=1;
                break;
            }
        }
        if(flag==1)
            printf("%s & %s are NOT anagrams.\n",s1, s2);
        else
            printf("%s & %s are anagrams.\n",s1, s2);
        
        flag=0;
    }
    
    return 0;
}