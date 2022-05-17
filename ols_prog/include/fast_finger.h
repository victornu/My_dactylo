//
// Created by vflavien on 2/8/22.
//

#ifndef FAST_FINGER_H_
    #define FAST_FINGER_H_

#define WRD_FOLDER "dictionnaries"

/* display.c */
void display_nexts(wchar_t **words);
size_t display_reads(wchar_t key, size_t *n, wchar_t *word);

#endif //FAST_FINGER_H_
