#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Jan 31 08:24:10 2021

@author: yiwen
"""

class stack:
    def __init__(self):     # constructor
        self._box = []
    def push(self, x):
        self._box.append(x)
    def pop(self):
        if self.size_of_stack() > 0:
            y = self._box[-1]
            self._box = self._box[:-1]
            return y
        else:
            print('nothing to pop...')
    def size_of_stack(self):
        return len(self._box)

