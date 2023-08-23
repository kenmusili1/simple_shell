#!/bin/bash
echo "Enter file name:"
read file_nm
cp template_c.c $file_nm
echo "File created"
vim $file_nm
