# 贡献者指南

欢迎提交 Pull Request，帮助我们优化文档。

## 文件内容规范

1. 请使用规范的 Markdown 格式编写内容，文件命名使用 `kebab-case` 格式。
2. 内容书写需要符合 [中文文案排版指北](https://github.com/sparanoid/chinese-copywriting-guidelines/blob/master/README.zh-Hans.md)；减少中文西化，使用现代汉语语序，避免大量使用宾语前置和被动语态。
3. 内容应当具有指导性、可读性、可理解性。

## 参考文档

- [Nextra](https://nextra.site/)：文档主题配置
  - [元数据文件](https://nextra.site/docs/file-conventions/meta-file)：导航栏配置
  - [内置组件](https://nextra.site/docs/built-ins)
    `Callout` 组件已全局注册，无需在 MDX 中 `import`
  - [Markdown 和 MDX](https://nextra.site/docs/guide/markdown)：文档标记语法
  - [提示框组件](https://nextra.site/docs/guide/github-alert-syntax)：GitHub 风格的提示框语法
- [Next.js](https://nextjs.org/)：文档主题框架
  - [部署](https://nextjs.org/docs/app/building-your-application/deploying)
    - [部署为静态网站](https://nextjs.org/docs/app/building-your-application/deploying/static-exports)
    - [在静态网站中启用 PageFind 搜索支持](https://the-guild.dev/blog/nextra-4#pagefind-setup)
    - 部署命令：`pnpm build`
    - 输出目录：`out`
- [JSX](https://zh-hans.react.dev/learn/writing-markup-with-jsx)：在 React 框架中描述 UI 的语法
- [Tailwind CSS](https://tailwindcss.com/docs/installation/framework-guides/nextjs)：原子化 CSS 框架
  - [Iconify for Tailwind CSS 4](https://iconify.design/docs/usage/css/tailwind/tailwind4/)：Iconify 图标库
  - [Yesicon](https://yesicon.app/)：Iconify 图标库的图标搜索工具
    请尽量使用同一个图标库中同一风格的图标

## 贡献方式

1. Fork 本仓库
2. 创建新的分支
3. 提交代码
4. 提交 Pull Request

## 贡献者公约（CODE OF CONDUCT）

请遵循 [贡献者公约](https://www.contributor-covenant.org/zh-cn/version/code_of_conduct/)。
