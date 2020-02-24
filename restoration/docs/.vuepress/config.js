module.exports = {
    title: "fff", // change this when done
    themeConfig: {
        nexLinks: true,
        prevLinks: true,
        smoothScroll: true,
        sidebar: [
            '/',
            {
                title: 'Summer IoT Studio',
                collapsable: true,
                sidebarDepth: 3,
                children: [
                    ['/summer/', 'What\'s this?'],
                    ['/summer/sprint1', '1st Sprint'],
                    ['/summer/sprint2', '2nd Sprint'],
                    ['/summer/sprint3', '3rd Sprint'],
                    ['/summer/sprint4', 'Final Sprint'],
                ]
            }
        ]
    }
}