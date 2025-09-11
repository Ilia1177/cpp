#!/bin/bash

# Check if remote is provided
if [ -z "$1" ]; then
    echo "Usage: $0 <remote>"
    exit 1
fi

REMOTE=$1

# Function to add or update subtree
manage_subtree() {
    local folder=$1
    local branch=$1
    
    if [ -d "$folder" ]; then
        echo "Updating existing subtree: $folder"
        git subtree pull --prefix=$folder $REMOTE $branch --squash
    else
        echo "Adding new subtree: $folder"
        git subtree add --prefix=$folder $REMOTE $branch --squash
    fi
}

# Ensure we're on main branch
git checkout main

# Process CPP00 through CPP09
for i in {0..9}; do
    branch=$(printf "CPP%02d" $i)
    echo "Processing: $branch"
    manage_subtree "$branch"
done
