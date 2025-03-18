---
author: [L33Z22L11]
---

# 贡献者指南

欢迎提交 Pull Request，帮助我们优化文档。

## 文件内容规范

1. 请使用规范的 Markdown 格式编写内容，文件命名使用 `kebab-case` 格式。
2. 内容书写尽量符合 [中文文案排版指北](https://github.com/sparanoid/chinese-copywriting-guidelines/blob/master/README.zh-Hans.md) [中文技术文档的写作规范(阮一峰)](https://github.com/ruanyf/document-style-guide)；减少中文西化，使用现代汉语语序，避免大量使用宾语前置和被动语态。
3. 内容应当具有指导性、可读性、可理解性。
4. 为某个文件贡献超过一大段中文内容时，可在 front-matter 的 `author: []` 中添加自己；为文件更新时效内容、修订重要错误或多个语法错误时，可在 `editor: []` 数组中添加自己。用 GitHub 用户名表示。

## 参考文档

- [Nextra](https://nextra.site/)：文档主题配置
  - [元数据文件](https://nextra.site/docs/file-conventions/meta-file)：导航栏配置
  - [内置组件](https://nextra.site/docs/built-ins)
    - 组件放入 `mdx-components.ts` 即可全局注册，不需 `import`
  - [其他配置](https://nextra.site/docs/guide)：文档标记语法
- [Next.js](https://nextjs.org/)：文档主题框架
  - [部署 Next.js](https://nextjs.org/docs/app/building-your-application/deploying)
  - [部署为静态网站](https://nextjs.org/docs/app/building-your-application/deploying/static-exports)
- [JSX](https://zh-hans.react.dev/learn/writing-markup-with-jsx)：在 React 框架中描述 UI 的语法
- [Tailwind CSS](https://tailwindcss.com/docs/installation/framework-guides/nextjs)：原子化 CSS 框架
- [Iconify Design](https://iconify.design/)：开源图标库
  - [Iconify for Tailwind CSS 4](https://iconify.design/docs/usage/css/tailwind/tailwind4/)：Iconify 图标库
  - [Yesicon](https://yesicon.app/)：Iconify 图标库的图标搜索工具
  - 请尽量使用同一个图标库（推荐 [Phospher](https://yesicon.app/ph)）中同一风格（推荐 bold）的图标
- [Prettier](https://prettier.io/)：代码格式化工具
  - [prettier-plugin-lint-md](https://github.com/lint-md/prettier-plugin)：中英文标点符号、空格、换行等格式化
  - [prettier-plugin-tailwindcss](https://github.com/tailwindlabs/prettier-plugin-tailwindcss)：Tailwind CSS 类名顺序规则

## 贡献方式

1. Fork 本仓库
2. 创建新的分支
3. 提交代码
4. 提交 Pull Request

## 贡献者公约（CODE OF CONDUCT）

请遵循 [贡献者公约](https://www.contributor-covenant.org/zh-cn/version/code_of_conduct/)。
