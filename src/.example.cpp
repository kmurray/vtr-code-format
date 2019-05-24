class Lexer {
    public:
    Lexer(FILE* file, Callback& callback);
    ~Lexer();
    Parser::symbol_type next_token();
    const char* text() const;
    int lineno() const;

    private:
    yyscan_t state_;
Callback& callback_;
};

/*
 * ArgumentGroup
 */
template<typename T, typename Converter>
Argument& ArgumentGroup::add_argument(ArgValue<T>& dest, std::string option) {
        return add_argument<T, Converter>(dest, option, std::string());
}

std::string escape_string(const std::string& near_text) {
       std::string escaped_text;

       for (char c : near_text) {
               if (c == '\n') {
                       escaped_text += "\\n";
                   
        }
        else if (c == '\r') {
                       escaped_text += "\\r";
                   
        }
        else {
                       escaped_text += c;
                   
        }
           
    }

       return escaped_text;
}
