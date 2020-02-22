module.exports = {
    title: "Bao Hoang",
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
                    ['/summer/sprint1', 'sprint 1'],
                ]
            }
        ]
    }
}