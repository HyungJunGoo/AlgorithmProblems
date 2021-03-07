#include <bits/stdc++.h>

using namespace std;

int solution(string word, vector<string> pages) {
    int answer = 0;
    map<string, int> basic_score;
    map<string, float> link_score;
    map<string, float> match_score;
    map<string, vector<string> > ex_link;
    // vector<string> web_url_for_index = {};
    map<string, int> web_url_for_index;
    int index = 0;
    for(string page : pages){
        // get web url
        string metadata = "<meta property=\"og:url\" content=\"https://";
        auto n = page.find(metadata);
        string web_url = page.substr(n+metadata.length(), 0);
        auto idx = n+metadata.size();
        while(true){
            if(page[idx] == '"')
                break;
            web_url += page[idx++];
        }
        web_url_for_index[web_url] = index++;
        // find all linked url
        string hrefdata = "<a href=\"https://";
        n = page.find(hrefdata);
        vector<string> linked_urls = {};
        while(n != string::npos){
            idx = n+hrefdata.length();
            string linked_url = "";
            while(true){
                if(page[idx] == '"')
                    break;
                linked_url += page[idx++];
            }
            linked_urls.push_back(linked_url);
            auto n_end = page.find("\">", idx);
            n = page.find(hrefdata, n_end);
        }

        // get body
        string body_area = "";
        n = page.find("<body>");
        auto n_2 = page.find("</body>");
        body_area = page.substr(n+6, (n_2-n-6));
        n = body_area.find("<");
        while(n != string::npos){
            n_2 = body_area.find(">");
            body_area.erase(n, n_2-n+1);
            n = body_area.find("<");
        }
        
        int basic_s = 0;
        string lower_body_area = "";
        for(char c : body_area){
            lower_body_area += tolower(c);
        }
        string n_word = "";
        for(char c : word)
            n_word += tolower(c);
        n = lower_body_area.find(n_word);
        while (n != string::npos)
        {
            if( !((int(lower_body_area[n+word.length()]) >= 97) && (int(lower_body_area[n+word.length()]) <123)) && !((int(lower_body_area[n+word.length()]) >= 65) && (int(lower_body_area[n+word.length()]) < 91)))
                basic_s += 1;
            n = lower_body_area.find(n_word, n+word.length()+1);
        }
        basic_score[web_url] = basic_s;
        link_score[web_url] = (float)basic_s / (float)linked_urls.size();
        match_score[web_url] = (float)basic_s;
        ex_link[web_url] = linked_urls;
    }

    for(auto n : ex_link){
        for(auto v : n.second){
            if(match_score[v])
                match_score[v] += link_score[n.first];
        }
    }
     
    float max_score = 0;
    for(auto n : match_score){
        if(web_url_for_index.find(n.first) != web_url_for_index.end()){
            if(max_score < n.second){
                max_score = n.second;
                answer = web_url_for_index[n.first];
            }
        }
    }
    return answer;
}

int main()
{
    vector<string> pages = {"<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>"};
    string word = "blind";
    return 0;
}