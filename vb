#!/bin/bash
# Add the changes to the staging area
git add vb monty.c monty.h opcode_push.c

# Commit the changes with a meaningful message
git commit -m "Updated files: monty.c, monty.h, opcode_push.c"

# Push the changes to the remote repository
git push
