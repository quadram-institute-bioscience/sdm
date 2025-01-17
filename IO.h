/* sdm: simple demultiplexer
Copyright (C) 2013  Falk Hildebrand

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
//most obvious input / output operations

#ifndef _IO_h
#define _IO_h


#include "containers.h"


typedef std::map<std::string, DNA*> DNAmap;


//void openOutFiles(string files, string fmt,string );
//void prepareOutFiles(OptContainer& cmdArgs);
//void read_fastq(OptContainer& cmdArgs, MultiDNA* MD,string fileS);
bool read_paired(OptContainer& cmdArgs, MultiDNA* MD, InputStreamer*,bool );
void read_paired_DNAready(DNA* tdn, DNA* tdn2, DNA* MIDseq, bool MIDuse, MultiDNA* MD, int& revConstellation);

//bool read_tripple(OptContainer& cmdArgs, MultiDNA* MD, InputStreamer*);

void separateByFile(Filters* mainFil,OptContainer& cmdArgs);

void threadAnalyzeDNA(DNA* tdn,MultiDNA* MD,int thrCnt);
void trippleThreadAnalyzeDNA(MultiDNA* MD, DNA* tdn,DNA *tdn2,DNA* MIDseq,bool changePHead);//,int thrCnt=0);

void read_single(OptContainer& cmdArgs, MultiDNA* MD,InputStreamer*);

bool readCmdArgs(int argc, char* argv[],OptContainer& cmdArgs);




//specialized functions .. end sdm after execution
void rewriteNumbers(OptContainer& cmdArgs);


void Announce_sdm();
void help_head();
void general_help();
void printCmdsHelp();
void printOptionHelp();
void printMapHelp();
void printVersion();


//bool readCmdArgs(int argc, char* argv[],map<char*, char*, lstr>& cmdArgs);
#endif