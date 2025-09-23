class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0,j=0;
        version1+=".";
        version2+=".";
        while(i<version1.size() && j<version2.size()){
            auto it = version1.find('.',i);
            auto itt = version2.find('.',j);
            if(it==string::npos||itt==string::npos){
                i = it+1;
                j=itt+1;
                break;
            }
            string s = version1.substr(i,it-i);
            string ss = version2.substr(j,itt-j);
            int t = stoi(s);
            int tt = stoi(ss);
            if(t<tt){
                return -1;
            }
            if(t>tt){
                return 1;
            }
            i=it+1;
            j=itt+1;
        }
        while(i<version1.size()){
            auto it = version1.find('.',i);
            string s = version1.substr(i,it-i);
            int t = stoi(s);
            if(t>0){
                return 1;
            }
            i=it+1;
        }
        while(j<version2.size()){
            auto itt = version2.find('.',j);
            string ss = version2.substr(j,itt-j);
            int tt = stoi(ss);
            if(tt>0){
                return -1;
            }
            j=itt+1;
        }
        return 0;
    }
};