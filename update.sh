#!/bin/bash

# Function to add or update subtree
manage_subtree() {
    local folder=$1
    local branch=$1
    
    if [ -d "$folder" ]; then
        echo "Updating existing subtree: $folder"
        git subtree pull --prefix=$folder home $branch --squash
    else
        echo "Adding new subtree: $folder"
        git subtree add --prefix=$folder home $branch --squash
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
