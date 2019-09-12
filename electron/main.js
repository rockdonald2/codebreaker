// require dependencies
const electron = require('electron');
const url = require('url');
const path = require('path');

const {
    app,
    BrowserWindow,
    Menu,
} = electron;

// SET ENV TO DEV
process.env.NODE_ENV = 'development';

let mainWindow;
let aboutWindow;

app.on('ready', () => {
    // create a new window
    mainWindow = new BrowserWindow({
        webPreferences: {
            nodeIntegration: true
        },
        title: 'codebreaker',
        width: 1024,
        height: 568
    });

    mainWindow.setFullScreenable(true);

    // load the html file into window
    mainWindow.loadURL(url.format({
        pathname: path.join(__dirname, 'mainWindow.html'),
        protocol: 'file:',
        slashes: true
    }));

    mainWindow.on('closed', () => {
        app.quit();
    });

    if (process.env.NODE_ENV == 'production') {
        mainWindow.setMenu(null);
    }
});

if (process.env.NODE_ENV != 'production') {

    const mainMenuTemplate = [{
        label: 'Game',
        submenu: [{
            label: 'About',
            click() {
                createAboutWindow();
            }
        }]
    }];

    mainMenuTemplate.push({
        label: 'devTools',
        submenu: [{
                label: 'Toggle devTools',
                accelerator: process.platform == 'darwin' ? 'Cmd+I' : 'Ctrl+I',
                click(item, focusedWindow) {
                    focusedWindow.toggleDevTools();
                }
            },
            {
                role: 'reload'
            }
        ]
    })

    const mainMenu = Menu.buildFromTemplate(mainMenuTemplate);

    Menu.setApplicationMenu(mainMenu);
}

let createAboutWindow = () => {
    // creater new window
    aboutWindow = new BrowserWindow({
        width: 300,
        height: 200,
        title: 'About codebreaker',
        webPreferences: {
            nodeIntegration: true
        }
    });
    // load the html file into the window
    aboutWindow.loadURL(url.format({
        pathname: path.join(__dirname, 'aboutWindow.html'),
        protocol: 'file:',
        slashes: true
    }));
    // garbage collection handle
    aboutWindow.on('closed', () => {
        addWindow = null;
    });

    aboutWindow.setMenu(null);
}
