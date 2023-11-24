class Solution {
public:
    using EntityChar = pair <string, char>;

    vector <EntityChar> entityList;

    string entityParser(string text) {
        entityList = vector({
            (EntityChar){"&quot;", '"'},
            (EntityChar){"&apos;", '\''},
            (EntityChar){"&amp;", '&'},
            (EntityChar){"&gt;", '>'},
            (EntityChar){"&lt;", '<'},
            (EntityChar){"&frasl;", '/'}
        });

        string r = "";
        for (int pos = 0; pos < text.size(); ) {
            bool isEntity = false;
            if (text[pos] == '&') {
                for (const auto &[e, c]: entityList) {
                    if (text.substr(pos, e.size()) == e) {
                        r.push_back(c);
                        pos += e.size();
                        isEntity = true;
                        break;
                    }
                }
            }
            if (!isEntity) {
                r.push_back(text[pos++]);
                continue;
            }
        }
        return r;
    }
};
