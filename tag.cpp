#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>

#include <taglib/fileref.h>
#include <taglib/tag.h>
#include <taglib/tpropertymap.h>

#include <getopt.h>
#include "bash_color.h"

using namespace std;

static struct option long_options[] =
{
    {"verbose", no_argument, 0, 'v'},
    {"help", no_argument, 0, 'h'},
    {"album", no_argument, 0, 'a'},
    {"artist", no_argument, 0, 'r'},
    {"track", no_argument, 0, 't'},
    {"disc", no_argument, 0, 'd'},
    {"title", no_argument, 0, 'n'},
    {"year", no_argument, 0, 'y'},
    {"genre", no_argument, 0, 'g'}
};

TagLib::String formatSeconds(int seconds)
{
  char secondsString[3];
  sprintf(secondsString, "%02i", seconds);
  return secondsString;
};

/*

 tag [opts] [INPUT] ... ]

*/

void PrintTags(int argc, char *argv[]);
void print_help();

const int DEFAULT_ARGC = 3;

int main(int argc, char *argv[])
{
    int opt = 0;
    int option_index = 0;
    bool file_flag = false;
    bool verbose_flag = false;
    
    optind = 0;
    while((opt = getopt_long(argc, argv, "hvartdnyg", long_options, &option_index)) != -1)
    {
        switch (opt)
        {
        case 'h':
            print_help();
            return 0;
        case 'v':
            verbose_flag = true;
            break;
        case 'f':
            file_flag = true;
            break;
        default: // unknown option before args
            fprintf(stderr, "Unexpected option, -h for help\n");
            return EXIT_FAILURE;
        }
    }

    // TagLib::FileRef f("test/test1.mp3");
    // TagLib::String artist = f.tag()->artist(); // artist == "Frank Zappa"
    
    // f.tag()->setAlbum("Fillmore East");
    // f.save();
    
    // TagLib::FileRef g("../test/test1.mp3");
    // TagLib::String album = g.tag()->album(); 
    // cout << "album: " << album << endl;
    
    // g.tag()->setTrack(1);
    // g.save();

    PrintTags(argc, argv);

    if (optind != (argc - DEFAULT_ARGC)) // not correct number of args
    {
        fprintf(stderr, "Expected argument after options, -h for help\n");
        exit(EXIT_FAILURE);
    }
          
    if (verbose_flag)
    {
        print_help();
    }

    if (!file_flag)
    {
        
    }
}

void 
PrintTags(int argc, char *argv[])
{
    for(int i = 1; i < argc; i++)
    {
        //cout << "******************** \"" << argv[i] << "\" ********************" << endl;
        TagLib::FileRef f(argv[i]);
        if(!f.isNull() && f.tag())
        {

            TagLib::Tag *tag = f.tag();

            //cout << "-- TAG (basic) --" << endl;
            cout << "title   - \"" << tag->title()   << "\"" << endl;
            cout << "artist  - \"" << tag->artist()  << "\"" << endl;
            cout << "album   - \"" << tag->album()   << "\"" << endl;
            cout << "year    - \"" << tag->year()    << "\"" << endl;
            cout << "comment - \"" << tag->comment() << "\"" << endl;
            cout << "track   - \"" << tag->track()   << "\"" << endl;
            cout << "genre   - \"" << tag->genre()   << "\"" << endl;

            // TagLib::PropertyMap tags = f.file()->properties();
            // unsigned int longest = 0;
            // for(TagLib::PropertyMap::ConstIterator i = tags.begin(); i != tags.end(); ++i)
            // {
            //     if (i->first.size() > longest)
            //     {
            //         longest = i->first.size();
            //     }
            // }

            // cout << "-- TAG (properties) --" << endl;
            // for(TagLib::PropertyMap::ConstIterator i = tags.begin(); i != tags.end(); ++i)
            // {
            //     for(TagLib::StringList::ConstIterator j = i->second.begin(); j != i->second.end(); ++j)
            //     {
            //         cout << left << std::setw(longest) << i->first << " - " << '"' << *j << '"' << endl;
            //     }
            // }
        }
    
        // if(!f.isNull() && f.audioProperties())
        // {
        //     TagLib::AudioProperties *properties = f.audioProperties();
        //     int seconds = properties->length() % 60;
        //     int minutes = (properties->length() - seconds) / 60;

        //     cout << "-- AUDIO --" << endl;
        //     cout << "bitrate     - " << properties->bitrate() << endl;
        //     cout << "sample rate - " << properties->sampleRate() << endl;
        //     cout << "channels    - " << properties->channels() << endl;
        //     cout << "length      - " << minutes << ":" << formatSeconds(seconds) << endl;
        // }
    }
}

void 
print_help()
{
    cout << "\n"
         << FMT_BOLD << "scanpf" << FMT_RESET << " "
         << "[OPTIONS] "
         << FMT_UNDERLINE << "INPUT_PATTERN" << FMT_RESET << " "
         << FMT_UNDERLINE << "OUTPUT_PATTERN" << FMT_RESET << " "
         << FMT_UNDERLINE << "[INPUT ...]" << FMT_RESET << "\n\n";
}
