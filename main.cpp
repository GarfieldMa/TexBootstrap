#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ostream& operator << (ostream&, const vector<string>&);

int main(int argc, char* argv[]){
    if (argc < 2)
        throw runtime_error("usage: tex-bootstrap filename");

    string document_class("\\documentclass{article}");

    vector<string> used_packages({
         "\\usepackage[utf8]{inputenc}",
         "\\usepackage[top=20mm,left=20mm]{geometry}",
         "\\usepackage{amsmath, amsthm,amsfonts,amssymb,pgfplots,graphicx,tikz}"});

    vector<string> macros({
          "\\def \\adj{{\\rm adj\\ }}",
          "\\def \\det{{\\rm det\\ }}",
          "\\def \\True{\\textbf{T}}",
          "\\def \\False{\\textbf{F}}",
          "\\def \\Real{\\mathbb{R}}",
          "\\def \\Natural{\\mathbb{N}}",
          "\\def \\Integer{\\mathbb{Z}}",
          "\\def \\Rational{\\mathbb{Q}}",
          "\\def \\Irrational{\\mathbb{I}}",
          "\\def \\powerset{\\mathcal{P}}",
          "\\def \\cos{{\\rm cos\\ }}",
          "\\def \\sin{{\\rm sin\\ }}"});

    vector<string> commands({
        "\\newcommand{\\tarc}{\\mbox{\\large$\\frown$}}",
        "\\newcommand{\\arc}[1]{\\stackrel{\\tarc}{#1}}",
        "\\newcommand{\\norm}[1]{||#1||}"});

    ofstream fout(argv[1]);

    if (fout.is_open()){

        fout << document_class << endl;

        fout << used_packages << endl;
        fout << macros << endl;
        fout << commands << endl;

        fout << "\\title{}" << endl;
        fout << "\\author{MA Rutian}" << endl;
        fout << "\\date{\\today}" << endl << endl;

        fout << "\\begin{document}" << endl;
        fout << "\\maketitle" << endl << endl;
        fout << "\\end{document}" << endl;
    }else
        throw runtime_error("fail to create file");

    return 0;
}

ostream& operator << (ostream& out, const vector<string>& vec){
    for (auto& str : vec)
        out << str << endl;
    return out;

}