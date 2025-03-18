# 西邮 Linux 兴趣小组培养计划<br>_Plan of Xiyou Linux Group_

> [!TIP]
>
> <!-- YarBor -->
>
> Hey, you found our treasure!
>
> [![访问](https://img.shields.io/badge/%E8%AE%BF%E9%97%AE-plan.xiyoulinux.com-green?style=for-the-badge)](https://plan.xiyoulinux.com)

整体参考路线：[Linux 系统软件开发方向的 RoadMap](https://github.com/xiyou-linuxer/Plan/issues/1)

知识点图鉴：[Favorites](https://fav.xiyoulinux.com/)

## 本地运行

```sh
git clone https://github.com/xiyou-linuxer/Plan.git xlg-plan
cd xlg-plan
# 安装 pnpm：package-manager install pnpm
# pnpm 换源：pnpm i -g nrm && nrm use taobao
pnpm i
pnpm dev
# 打开网站：browser open http://localhost:3000
```

需要安装 `Iconify IntelliSense` `Prettier` `MDX` VS Code 插件以规范代码并高亮语法。

### 格式化代码

项目启用了保存时自动格式化，再也不怕格式混乱了！（VS Code 中按 F1 输入`fswf`以保存时避免格式化）

但是保存时格式化不会在 VS Code 自动保存时触发，所以我给出了检查和修复格式的命令，用于维护代码规范。

```sh
pnpm lint       # check only
pnpm lint:fix   # check and fix
```

## 部署

项目可以在各类 Serverless 平台上部署。

- 部署命令：`pnpm build`
- 输出目录：`out`

### 疑难解答

- Cloudflare Pages 需要手动配置环境变量 `NODE_VERSION` 为较高的版本，如 `22.14.0`。

## 开源信息

- 代码协议：[MIT](https://github.com/xiyou-linuxer/Plan/blob/main/LICENSE)
- 文本协议：[CC BY-NC-SA 4.0](https://creativecommons.org/licenses/by-nc-sa/4.0/deed.zh-hans)
- 贡献者指南：[网页](https://plan.xiyoulinux.com/manual/contributing/) · [contributing.md](./content/manual/contributing)
- 更新日志：[网页](https://plan.xiyoulinux.com/manual/changelog/) · [changelog.md](./content/manual/changelog)

<br>

[![贡献者](https://contrib.rocks/image?repo=xiyou-linuxer/Plan)](https://github.com/xiyou-linuxer/Plan/graphs/contributors)

## _Carpe diem, seize the day_ <img align="right" src="https://avatars.githubusercontent.com/xiyou-linuxer" alt="一只来自西安邮电大学的小企鹅" width="64">
