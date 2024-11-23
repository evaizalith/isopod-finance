# isopod-finance

Isopod-Finance, or ispdf, is a CLI finance manager.

## Installation

1. Ensure sqlite3 is installed on your system.
2. Execute the following commands:
`git clone https://github.com/evaizalith/isopod-finance.git`
`cd isopod-finance`
`chmod +x install.sh`
`./install.sh`

You will be prompted to enter your sudo password to install the compiled binary into your /bin/ folder. If you choose not to enter your sudo password, the binary will be placed in the build directory.

You can uninstall using the uninstall script, or by deleting the file 'ispdf' located in /bin/

## Usage

ispdf takes several arguments including:

    -h 
    
        Displays the help menu 
        
    -a 
    
        Add a transaction record
        
    -r 
        Remove a transaction record

For a full list of options, run `ispdf -h`
