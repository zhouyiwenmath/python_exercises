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
            self._box = self._box[:-1]
        else:
            print('nothing to pop...')
    def check(self):
        if self.size_of_stack() > 0:
            return self._box[-1]
        else:
            print('empty stack...')
    def empty_stack(self):
        self._box = []
    def size_of_stack(self):
        return len(self._box)
    def is_empty(self):
        return len(self._box) == 0
    
    
class queue:
    def __init__(self):     # constructor
        self._box = []
    def push(self, x):
        self._box.append(x)
    def pop(self):
        if self.size_of_stack() > 0:
            self._box = self._box[1:]
        else:
            print('nothing to pop...')
    def check(self):
        if self.size_of_stack() > 0:
            return self._box[0]
        else:
            print('empty stack...')
    def empty_stack(self):
        self._box = []
    def size_of_stack(self):
        return len(self._box)
    def is_empty(self):
        return len(self._box) == 0


class binary_tree_node:
    def __init__(self, data):     # constructor
        self.data = data
        self.left = None
        self.right = None
    def assign_left(self, node):
        self.left = node
    def remove_left(self):
        self.left = None
    def is_empty_left(self):
        return self.left is None
    def assign_right(self, node):
        self.right = node
    def remove_right(self):
        self.right = None
    def is_empty_right(self):
        return self.right is None
    def get_data(self):
        return self.data
    def edit_data(self, data):
        self.data = data
